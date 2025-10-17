// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillButtons.generated.h"

UENUM(BlueprintType)
enum class ESkillCategory : uint8
{
	Skills      UMETA(DisplayName = "Skills"),
	Strength    UMETA(DisplayName = "Strength"),
	Health      UMETA(DisplayName = "Health")
};
/**
 * 
 */
USTRUCT(BlueprintType)
struct FSkillData
{
  GENERATED_BODY()

public:

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  int32 SkillID;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  TArray<int32> PrerequisiteIDs;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  bool bIsActive;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  int32 SkillCost;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  ESkillCategory Category;

  
};


class UButton;
class USkillTree;
class UTextBlock;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSkillUnlocked, USkillButtons*, _SkillButton);

UCLASS()
class PF_SKILLTREE_LFS_API USkillButtons : public UUserWidget
{
	GENERATED_BODY()
public: 

  UPROPERTY(meta = (BindWidget))
  UButton* Button;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  FSkillData SkillInfo;

  UPROPERTY()
  USkillTree* m_skillTree;

  UFUNCTION()
  void OnButtonClicked();
  UFUNCTION()
  void UnlockButton();

  UPROPERTY(BlueprintAssignable, Category = "Skill")
  FOnSkillUnlocked OnSkillUnlocked;

protected:

	virtual void NativeConstruct() override;

};
