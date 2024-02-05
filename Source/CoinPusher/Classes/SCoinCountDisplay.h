// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class COINPUSHER_API SCoinCountDisplay : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SCoinCountDisplay)
        {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

    void SetDisplayedVariable(int32 NewValue);

private:
    TSharedPtr<STextBlock> VariableDisplayText;
};
