// Fill out your copyright notice in the Description page of Project Settings.


#include "SCoinCountDisplay.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SCoinCountDisplay::Construct(const FArguments& InArgs)
{
    // Create the widget
    ChildSlot
        [
            SNew(SVerticalBox)
                + SVerticalBox::Slot()
                .AutoHeight()
                [
                    // Text block to display the variable
                    SAssignNew(VariableDisplayText, STextBlock)
                        .Text(FText::FromString(TEXT("Variable: 0"))) // Default text
                ]
        ];
}

void SCoinCountDisplay::SetDisplayedVariable(int32 NewValue)
{
    // Update the displayed variable
    if (VariableDisplayText.IsValid())
    {
        VariableDisplayText->SetText(FText::FromString(FString::Printf(TEXT("Variable: %d"), NewValue)));
    }
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
