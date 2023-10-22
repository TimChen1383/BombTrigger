// Fill out your copyright notice in the Description page of Project Settings.


#include "BombTrigger.h"

// Sets default values
ABombTrigger::ABombTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create a key object and sphere collision
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	SphereDetection = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Detection"));
	KeyObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Object"));
	SphereDetection->SetupAttachment(SceneComponent);
	KeyObject->SetupAttachment(SceneComponent);
	SphereDetection->SetSphereRadius(DetectRadius);

	//When sphere collision has been overlapped, link to explosion function
	SphereDetection->OnComponentBeginOverlap.AddDynamic(this, &ABombTrigger::SphereOverlap);
	
}

// Called when the game starts or when spawned
void ABombTrigger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABombTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Run Counter when object has been overlapped
void ABombTrigger::SphereOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CountDownCounter();
	//fleshing object's material using Dynamic Material instance
	auto CurrentMaterial = KeyObject->GetMaterial(0);
	auto DynamicMaterial = KeyObject->CreateDynamicMaterialInstance(0,CurrentMaterial);
	DynamicMaterial->SetScalarParameterValue("HighLight", 5.0f);
	KeyObject->SetMaterial(0, DynamicMaterial);
	UE_LOG(LogTemp, Warning, TEXT("Material Highlighted"));
}

//Start running counter and fleshing material
void ABombTrigger::CountDownCounter()
{
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &ABombTrigger::ExplosionAction, 1.0f, true, 0.0);
	
	
}

//Send count down message and run explosion, destory key object component after explosion
void ABombTrigger::ExplosionAction()
{
	if(CountDountSeconds == 0)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this->GetWorld(), ExplosionParticle, GetActorTransform());
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().ClearTimer(Handle);
		CountDountSeconds = -1;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("Stop Counting"));
		KeyObject->DestroyComponent();
	}
	else if(CountDountSeconds >= 0)
	{
		CountDountSeconds -= 1;
		FString DelayTimeString = FString::SanitizeFloat(CountDountSeconds);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, *DelayTimeString);	
	}
	else
	{
		
	}
}



//Create a key object and sphere collision
//When sphere collision has been overlapped, add dynamic function
	// change the material of key object
	// count down timer
	// when count down timer reach zero, run explosion

// try use Usubclassof


