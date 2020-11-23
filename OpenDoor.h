// Copyright Dwayke.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRABANDESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();

	bool OpenDoorSound = false;
	bool CloseDoorSound = true;

private:
	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.0f;
	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
		float DoorCloseSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;
	UPROPERTY(EditAnywhere)
		float TargetYaw = -105.0f;	
	UPROPERTY(EditAnywhere)
		float MassToOpenDoors = 50.0f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;
};
