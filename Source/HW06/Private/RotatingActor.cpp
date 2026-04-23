
#include "RotatingActor.h"
#include "Components/StaticMeshComponent.h"

ARotatingActor::ARotatingActor()
{
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));

	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, 1.f, 0.f));
}
