// RotaingActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class HW06_API ARotatingActor : public AActor
{
	GENERATED_BODY()

public:
	ARotatingActor();

	virtual void Tick(float DeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Body;
};
