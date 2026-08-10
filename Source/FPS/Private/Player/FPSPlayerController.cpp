// No Copyright.

#include "Player/FPSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/FPSPlayerInputComponent.h"
#include "EnhancedInput/FPSPlayerInputDataAsset.h"
#include "Character/FPSPlayerCharacter.h"

AFPSPlayerController::AFPSPlayerController()
{
	bReplicates = true;
}

void AFPSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsLocalPlayerController()) return;
	
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	check(LocalPlayer);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	
	check(Subsystem);
	check(PlayerInputDataAsset);
	check(PlayerInputDataAsset->FPSMappingContext);
	Subsystem->AddMappingContext(PlayerInputDataAsset->FPSMappingContext, 0);
}

void AFPSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UFPSPlayerInputComponent* FPSPlayerInputComponent = CastChecked<UFPSPlayerInputComponent>(InputComponent);
	check(PlayerInputDataAsset);
	
	/** Look Action Binding */
	check(PlayerInputDataAsset->LookAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->LookAction, ETriggerEvent::Triggered,
		this, &AFPSPlayerController::Input_Look);
	
	/** Move Action Binding */
	check(PlayerInputDataAsset->MoveAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->MoveAction, ETriggerEvent::Triggered,
		this, &AFPSPlayerController::Input_Move);
	
	/** Jump Action Binding */
	check(PlayerInputDataAsset->JumpAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->JumpAction, ETriggerEvent::Started,
		this, &AFPSPlayerController::Input_JumpPressed);
	
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->JumpAction, ETriggerEvent::Completed,
		this, &AFPSPlayerController::Input_CrouchReleased);
	
	/** Crouch Action Binding */
	check(PlayerInputDataAsset->CrouchAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->CrouchAction, ETriggerEvent::Started,
		this, &AFPSPlayerController::Input_CrouchPressed);
	
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->CrouchAction, ETriggerEvent::Completed,
		this, &AFPSPlayerController::Input_CrouchReleased);
}

void AFPSPlayerController::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisValue = InputActionValue.Get<FVector2D>();
	
	if (!FMath::IsNearlyZero(InputAxisValue.X))
	{
		AddYawInput(InputAxisValue.X);
	}
	
	if (!FMath::IsNearlyZero(InputAxisValue.Y))
	{
		AddPitchInput(InputAxisValue.Y);
	}
}

void AFPSPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisValue = InputActionValue.Get<FVector2D>();
	
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	APawn* ControlledPawn = Cast<APawn>(GetPawn());
	if (!IsValid(ControlledPawn)) return;
	
	if (!FMath::IsNearlyZero(InputAxisValue.X))
	{
		const FVector RightDirection = YawRotation.RotateVector(FVector::RightVector);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisValue.X);
	}
	
	if (!FMath::IsNearlyZero(InputAxisValue.Y))
	{
		const FVector ForwardDirection = YawRotation.RotateVector(FVector::ForwardVector);
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisValue.Y);
	}
}

void AFPSPlayerController::Input_JumpPressed()
{
	AFPSPlayerCharacter* PlayerCharacter = Cast<AFPSPlayerCharacter>(GetCharacter());
	if (!IsValid(PlayerCharacter)) return;
	
	PlayerCharacter->Jump();
}

void AFPSPlayerController::Input_JumpReleased()
{
	AFPSPlayerCharacter* PlayerCharacter = Cast<AFPSPlayerCharacter>(GetCharacter());
	if (!IsValid(PlayerCharacter)) return;
	
	PlayerCharacter->StopJumping();
}

void AFPSPlayerController::Input_CrouchPressed()
{
	AFPSPlayerCharacter* PlayerCharacter = Cast<AFPSPlayerCharacter>(GetCharacter());
	if (!IsValid(PlayerCharacter)) return;
	
	PlayerCharacter->Crouch();
}

void AFPSPlayerController::Input_CrouchReleased()
{
	AFPSPlayerCharacter* PlayerCharacter = Cast<AFPSPlayerCharacter>(GetCharacter());
	if (!IsValid(PlayerCharacter)) return;
	
	PlayerCharacter->UnCrouch();
}
