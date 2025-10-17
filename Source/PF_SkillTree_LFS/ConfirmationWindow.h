// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ConfirmationWindow.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConfirm);
class UButton;

UCLASS()
class PF_SKILLTREE_LFS_API UConfirmationWindow : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnConfirm OnConfirm;

	UFUNCTION()
	void ConfirmAction();

	UFUNCTION()
	void CancelAction();

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonConfirm;
	UPROPERTY(meta = (BindWidget))
	UButton* ButtonCancel;

protected:

	virtual void NativeConstruct() override;
};
