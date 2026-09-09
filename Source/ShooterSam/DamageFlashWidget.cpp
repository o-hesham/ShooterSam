#include "DamageFlashWidget.h"

#include "Rendering/DrawElements.h"
#include "Styling/CoreStyle.h"

float UDamageFlashWidget::GetFlashOpacity(float RemainingTime, float Duration)
{
	if (Duration <= 0.0f || RemainingTime <= 0.0f)
	{
		return 0.0f;
	}

	return FMath::Clamp(RemainingTime / Duration, 0.0f, 1.0f);
}

float UDamageFlashWidget::GetEdgeOpacity(float NormalizedDistance)
{
	const float Distance = FMath::Clamp(NormalizedDistance, 0.0f, 1.0f);
	const float SmoothDistance = Distance * Distance * (3.0f - 2.0f * Distance);
	return 1.0f - SmoothDistance;
}

void UDamageFlashWidget::PlayDamageFlash()
{
	FlashRemainingTime = FlashDuration;
}

void UDamageFlashWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	FlashRemainingTime = FMath::Max(0.0f, FlashRemainingTime - InDeltaTime);
}

int32 UDamageFlashWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
	int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const float Opacity = GetFlashOpacity(FlashRemainingTime, FlashDuration);
	if (Opacity <= 0.0f)
	{
		return LayerId;
	}

	const FVector2D Size = AllottedGeometry.GetLocalSize();
	const float FadeWidthX = Size.X * EdgeFadeDistance;
	const float FadeWidthY = Size.Y * EdgeFadeDistance;
	const FSlateBrush* Brush = FCoreStyle::Get().GetBrush(TEXT("WhiteBrush"));

	for (int32 Step = 0; Step < GradientSteps; ++Step)
	{
		const float OuterRatio = static_cast<float>(Step) / GradientSteps;
		const float InnerRatio = static_cast<float>(Step + 1) / GradientSteps;
		const float OuterInsetX = FadeWidthX * OuterRatio;
		const float OuterInsetY = FadeWidthY * OuterRatio;
		const float RingWidthX = FadeWidthX * (InnerRatio - OuterRatio);
		const float RingWidthY = FadeWidthY * (InnerRatio - OuterRatio);
		const FLinearColor Tint(0.9f, 0.0f, 0.0f,
			Opacity * GetEdgeOpacity(OuterRatio) * 0.85f);

		FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(
			FVector2D(RingWidthX, Size.Y - OuterInsetY * 2.0f),
			FSlateLayoutTransform(FVector2D(OuterInsetX, OuterInsetY))), Brush, ESlateDrawEffect::None, Tint);
		FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(
			FVector2D(RingWidthX, Size.Y - OuterInsetY * 2.0f),
			FSlateLayoutTransform(FVector2D(Size.X - OuterInsetX - RingWidthX, OuterInsetY))), Brush, ESlateDrawEffect::None, Tint);
		FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(
			FVector2D(Size.X - OuterInsetX * 2.0f, RingWidthY),
			FSlateLayoutTransform(FVector2D(OuterInsetX, OuterInsetY))), Brush, ESlateDrawEffect::None, Tint);
		FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(
			FVector2D(Size.X - OuterInsetX * 2.0f, RingWidthY),
			FSlateLayoutTransform(FVector2D(OuterInsetX, Size.Y - OuterInsetY - RingWidthY))), Brush, ESlateDrawEffect::None, Tint);
	}

	return LayerId + 1;
}
