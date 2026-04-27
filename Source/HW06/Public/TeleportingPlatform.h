
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleportingPlatform.generated.h"

UCLASS()
class HW06_API ATeleportingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ATeleportingPlatform();

protected:
	virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* MeshComp;

    // 타이머 핸들 선언
    FTimerHandle TeleportTimerHandle;

    // 주기적으로 호출될 이동 함수 선언
    void TeleportRandomly();
};
