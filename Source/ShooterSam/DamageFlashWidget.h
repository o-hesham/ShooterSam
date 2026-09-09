#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "DamageFlashWidget.generated.h"

UCLASS()
class SHOOTERSAM_API UDamageFlashWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	static float GetFlashOpacity(float RemainingTime, float Duration);
	static float GetEdgeOpacity(float NormalizedDistance);

	void PlayDamageFlash();

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
		int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

private:
	static constexpr float FlashDuration = 0.35f;
	static constexpr float EdgeFadeDistance = 0.08f;
	static constexpr int32 GradientSteps = 16;

	float FlashRemainingTime = 0.0f;
};
