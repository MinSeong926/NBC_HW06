
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisappearingPlatform.generated.h"

UCLASS()
class HW06_API ADisappearingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ADisappearingPlatform();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComp;

	// 타이머 핸들 선언
	FTimerHandle TimerHandle;

	// 일정 주기마다 호출될 함수
	void ToggleVisibility();
};
