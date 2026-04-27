
#include "DisappearingPlatform.h"
#include "TimerManager.h"

ADisappearingPlatform::ADisappearingPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void ADisappearingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	// 2초마다 ToggleVisibility 함수 실행
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADisappearingPlatform::ToggleVisibility, 2.0f, true);
}

void ADisappearingPlatform::ToggleVisibility() {
	bool bIsHidden = MeshComp->bHiddenInGame;

	// 렌더링 상태 반전
	MeshComp->SetHiddenInGame(!bIsHidden);

	MeshComp->SetCollisionEnabled(bIsHidden ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
}
