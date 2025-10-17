// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTree.h"
#include "SkillButtons.h"
#include "Components/Widget.h"
#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"

void USkillTree::NativeConstruct()
{
  Super::NativeConstruct();

  if (!WidgetTree || !WidgetTree->RootWidget)
  {
    return;
  }
  m_puntosmejora = 78;
  m_Puntosmejoratxt->SetText(FText::AsNumber(m_puntosmejora));

  TArray<UWidget*> AllWidgets;
  WidgetTree->GetAllWidgets(AllWidgets);

  for (UWidget* Widget : AllWidgets)
  {
    if (USkillButtons* SkillBtn = Cast<USkillButtons>(Widget))
    {
      SkillBtn->m_skillTree = this;
      SkillBtn->OnSkillUnlocked.AddDynamic(this, &USkillTree::ModifySkillPoints);
      SkillButtons.Add(SkillBtn);

    }
  }

  for (USkillButtons* SkillBtn : SkillButtons)
  {
    if (SkillBtn) 
    {
      switch (SkillBtn->SkillInfo.Category)
      {
      case ESkillCategory::Health:
        SkillButtonsHealth.Add(SkillBtn->SkillInfo.SkillID, SkillBtn);
        break;
      case ESkillCategory::Strength:
        SkillButtonsStrength.Add(SkillBtn->SkillInfo.SkillID, SkillBtn);
        break;
      case ESkillCategory::Skills:
        SkillButtonsSkills.Add(SkillBtn->SkillInfo.SkillID, SkillBtn);
        break;
      }

    }
  }

 
}

bool USkillTree::CanUnlockButton(USkillButtons* _Button)
{

  TArray<int32> Prereqs = _Button->SkillInfo.PrerequisiteIDs;

 
  if (Prereqs.Num() == 0) 
  {
    return true;
  }

  
  for (int32 PrereqID : Prereqs)
  {
    const USkillButtons* Prev = nullptr;
    switch (_Button->SkillInfo.Category)
    {
    case ESkillCategory::Health:
      Prev = SkillButtonsHealth.FindRef(PrereqID);
      break;
    case ESkillCategory::Strength:
      Prev = SkillButtonsStrength.FindRef(PrereqID);
      break;
    case ESkillCategory::Skills:
      Prev = SkillButtonsSkills.FindRef(PrereqID);
      break;
    }

    if (Prev && Prev->SkillInfo.bIsActive)
    {
      return true;
    }
  }

  return false;
}

void USkillTree::ModifySkillPoints(USkillButtons* _Button)
{
  if (m_puntosmejora>= _Button->SkillInfo.SkillCost)
  {
    m_puntosmejora -= _Button->SkillInfo.SkillCost;
    m_Puntosmejoratxt->SetText(FText::AsNumber(m_puntosmejora));
  }
  else 
  {
    WarningTxt->SetText(FText::FromString("PUNTOS INSUFICIENTES"));

    FTimerHandle TimerWarningText;
    GetWorld()->GetTimerManager().SetTimer(
      TimerWarningText,
      [this]()
      {
        WarningTxt->SetText(FText::FromString(""));
      },
      1.0f,
      false
    );
  }
}
