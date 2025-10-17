// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillTree.generated.h"


class UCanvasPanel;
class UImage;
class UTextBlock;
class USkillButtons;
class UConfirmationWindow;
/**
 * 
 */
UCLASS()
class PF_SKILLTREE_LFS_API USkillTree : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
  UConfirmationWindow* BP_ConfirmationWindow;

	bool CanUnlockButton(USkillButtons* _Button);

	UFUNCTION()
	void ModifySkillPoints(USkillButtons* _Button);

	UPROPERTY(meta = (BindWidget))
	UTextBlock* m_Puntosmejoratxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* WarningTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	int32 m_puntosmejora;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TMap<int32, USkillButtons*> SkillButtonsSkills;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TMap<int32, USkillButtons*> SkillButtonsHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TMap<int32, USkillButtons*> SkillButtonsStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional), Category = "UI")
	TArray<USkillButtons*> SkillButtons;

protected:

	virtual void NativeConstruct() override;

private:



};
