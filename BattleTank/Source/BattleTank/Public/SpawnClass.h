// Copyright by Vitaliy Novoselov 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SprungWheel.h"
#include "SpawnClass.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API USpawnClass : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnClass();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Config
	UPROPERTY(EditAnywhere, Category = "Config")
	TSubclassOf<AActor> SpawnClass;

};
