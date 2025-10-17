// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillButtons.h"
#include "Components/Button.h"
#include "SkillTree.h"
#include "ConfirmationWindow.h"
#include "Components/TextBlock.h"

void USkillButtons::NativeConstruct()
{
  Super::NativeConstruct();

  if (Button)
  {
    Button->OnClicked.AddDynamic(this, &USkillButtons::OnButtonClicked);
    
  }
  
}
void USkillButtons::OnButtonClicked()
{

  if (!m_skillTree) return;

  if (Button)
  {
    if (m_skillTree->CanUnlockButton(this) && m_skillTree->m_puntosmejora >= SkillInfo.SkillCost)
    {
      if (m_skillTree && m_skillTree->BP_ConfirmationWindow)
      {
        m_skillTree->BP_ConfirmationWindow->OnConfirm.Clear();
        m_skillTree->BP_ConfirmationWindow->OnConfirm.AddDynamic(this, &USkillButtons::UnlockButton);
        m_skillTree->BP_ConfirmationWindow->SetVisibility(ESlateVisibility::Visible);
      }
    }
    else 
    {
      UnlockButton();
    }
    
    
  }
  
  
}

void USkillButtons::UnlockButton()
{

  if (m_skillTree->m_puntosmejora >= SkillInfo.SkillCost)
  {
    if (m_skillTree->CanUnlockButton(this) && !SkillInfo.bIsActive)
    {
      OnSkillUnlocked.Broadcast(this);
      SkillInfo.bIsActive = true;

      FLinearColor NewColor = FLinearColor::Green;

      Button->SetBackgroundColor(NewColor);
      Button->SetIsEnabled(false);

      UE_LOG(LogTemp, Warning, TEXT("DESBLOQUEADO"));
    }
    else
    {
      FLinearColor OriginalColor = Button->BackgroundColor;

      Button->SetBackgroundColor(FLinearColor::Red);

      FTimerHandle TempHandle;
      GetWorld()->GetTimerManager().SetTimer(
        TempHandle,
        [this, OriginalColor]()
        {
          if (Button)
          {
            Button->SetBackgroundColor(OriginalColor);
          }
        },
        1.0f,
        false
      );


    }
  }
  else
  {
    OnSkillUnlocked.Broadcast(this);
  }
  
  
}

