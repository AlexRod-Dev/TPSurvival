// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "TPSurvivalCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ATPSurvivalCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Third Person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TPPCamera;

	/** First Person Camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FPPCamera;

	/** Mesh da arma */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	class USkeletalMesh* WeaponMesh;
	
	// /** Follow camera */
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	// UCameraComponent* FollowCamera;


	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Aim Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Aim;

	/** Aim Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Sprint;

	/** Switch POV Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SwitchPov;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Interact;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Fire;
	
	
public:
	ATPSurvivalCharacter();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return TPPCamera; }

	//FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FPPCamera; }

protected:

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	

	// To add mapping context
	virtual void BeginPlay();

	

public:


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	bool bIsAiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	bool bIsTPP;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterMovement)
	bool bIsSprinting;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterMovement)
	float movementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterMovement)
	float sneakMovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterMovement)
	float sprintMovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
	float currentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
	float maxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float currentFood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float maxFood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float currentWater;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float maxWater;
	// UPROPERTY(EditAnywhere, Category = "Pickup")
	// ASkeletalMeshActor* wielded;

	FTimerHandle foodTimerHandle;
	FTimerHandle waterTimerHandle;

	UPROPERTY(EditAnywhere, Category="Collision")
	TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;
	
protected:
	
	
	void AimDownSight();
	void StopAimDownSight();
	
	 void StartSprint();
	 void StopSprint();
	
	void SwitchCamera();

	void WaterDecrement();
	void FoodDecrement();
	void Use();

	
};

