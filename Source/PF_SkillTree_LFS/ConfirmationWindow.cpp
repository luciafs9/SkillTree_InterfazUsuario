// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfirmationWindow.h"
#include "Components/Button.h"


void UConfirmationWindow::NativeConstruct()
{
  Super::NativeConstruct();

  if (ButtonConfirm)
  {
    ButtonConfirm->OnClicked.AddDynamic(this, &UConfirmationWindow::ConfirmAction);

  }
  if (ButtonCancel)
  {
    ButtonCancel->OnClicked.AddDynamic(this, &UConfirmationWindow::CancelAction);

  }
}
void UConfirmationWindow::ConfirmAction()
{
  OnConfirm.Broadcast();
  SetVisibility(ESlateVisibility::Collapsed);
}

void UConfirmationWindow::CancelAction()
{
  SetVisibility(ESlateVisibility::Collapsed);
}


