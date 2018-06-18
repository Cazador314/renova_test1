// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RenovaTest1Character.generated.h"

UCLASS(Blueprintable)
class ARenovaTest1Character : public ACharacter
{
	GENERATED_BODY()

public:
	ARenovaTest1Character();

	/**Accesor function for initial timer */
	UFUNCTION(BlueprintPure, Category = "Timer")
		float GetInitialTimer();

	/**Accesor function for current timer */
	UFUNCTION(BlueprintPure, Category = "Timer")
		float GetCurrentTimer();

	/**Updates current timer
	@param Timer This is the timer to be used for cooldowns
	*/
	UFUNCTION(BlueprintCallable, Category = "Timer")
		void UpdateCurrentTimer(float Timer);


	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere, Category = "Stamina")
		float InitialTimer;

	UPROPERTY(EditAnywhere, Category = "Stamina")
		float CurrentTimer;

};

