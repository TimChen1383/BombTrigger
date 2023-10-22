// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "BombTrigger.generated.h"

UCLASS()
class UECPP_PRACTICE_API ABombTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category="BombTrigger")
	class UStaticMeshComponent* KeyObject;

	UPROPERTY(EditAnywhere, Category="BombTrigger")
	float DetectRadius = 150.0f;

	UPROPERTY(EditAnywhere, Category="BombTrigger")
	float CountDountSeconds = 5.0f;

	UPROPERTY(EditAnywhere, Category="BombTrigger")
	UParticleSystem* ExplosionParticle;
	
	UFUNCTION()
	void CountDownCounter();

	UFUNCTION()
	void ExplosionAction();

	UFUNCTION()
	void SphereOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	class USceneComponent* SceneComponent;
	class USphereComponent* SphereDetection;
	

	
};
