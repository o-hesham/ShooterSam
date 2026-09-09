// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "Gun.generated.h"

UCLASS()
class SHOOTERSAM_API AGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent *SceneRoot;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent *Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	UNiagaraComponent *MuzzleFlashParticleSystem;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UNiagaraSystem *ImpactParticleSytem;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float BulletDamage = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float MaxRange = 10000.0f;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase *ShootSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase *ImpactSound;

	AController *OwnerController;

	void PullTrigger();
};
