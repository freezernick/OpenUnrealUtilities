﻿// Copyright (c) 2022 Jonas Reich

#include "GameplayDebugger/GameplayDebugger_DisplayDebugManager.h"

#if WITH_GAMEPLAY_DEBUGGER

	#include "Engine/Canvas.h"
	#include "GameplayDebuggerTypes.h"

constexpr int32 NumberOfColumnsPerScreen = 2;

FGameplayDebugger_DisplayDebugManager::FGameplayDebugger_DisplayDebugManager(
	FGameplayDebuggerCanvasContext& InCanvasContext) :
	CanvasContext(InCanvasContext)
{
	NextColumnXPos = 0.f;
	MaxCursorY = FMath::Max(CanvasContext.CursorY, MaxCursorY);
}

void FGameplayDebugger_DisplayDebugManager::SetDrawColor(const FColor& NewColor)
{
	DrawColor = NewColor;
}

void FGameplayDebugger_DisplayDebugManager::SetLinearDrawColor(const FLinearColor& NewColor)
{
	DrawColor = NewColor.ToFColor(true);
}

void FGameplayDebugger_DisplayDebugManager::DrawString(const FString& InDebugString, const float& OptionalXOffset)
{
	AddColumnIfNeeded();
	const float PreviousY = CanvasContext.CursorY;
	{
		TGuardValue<float> ScopedCursorX(CanvasContext.CursorX, CanvasContext.CursorX + OptionalXOffset);
		CanvasContext.Print(DrawColor, InDebugString);
	}
	float SizeX = 0.0f, SizeY = 0.0f;
	CanvasContext.MeasureString(InDebugString, OUT SizeX, OUT SizeY);
	NextColumnXPos = FMath::Max(NextColumnXPos, CanvasContext.CursorX + OptionalXOffset + SizeX);
	CanvasContext.CursorY = FMath::Max(PreviousY + GetYStep(), CanvasContext.CursorY);
	MaxCursorY = FMath::Max(CanvasContext.CursorY, MaxCursorY);
	AddColumnIfNeeded();
}

void FGameplayDebugger_DisplayDebugManager::AddColumnIfNeeded()
{
	const float YStep = GetYStep();
	if (CanvasContext.Canvas.IsValid() && (CanvasContext.CursorY + YStep * 2) > CanvasContext.Canvas->ClipY)
	{
		CanvasContext.DefaultX += CanvasContext.Canvas->ClipX / NumberOfColumnsPerScreen;
		CanvasContext.CursorX = CanvasContext.DefaultX;
		CanvasContext.CursorY = CanvasContext.DefaultY;
	}
}

float FGameplayDebugger_DisplayDebugManager::GetYStep() const
{
	return CanvasContext.Font->GetMaxCharHeight() * 1.15f;
}

float FGameplayDebugger_DisplayDebugManager::GetXPos() const
{
	return CanvasContext.CursorX;
}

float FGameplayDebugger_DisplayDebugManager::GetYPos() const
{
	return CanvasContext.CursorY;
}

void FGameplayDebugger_DisplayDebugManager::SetYPos(const float NewYPos)
{
	CanvasContext.CursorY = NewYPos;
	MaxCursorY = FMath::Max(CanvasContext.CursorY, MaxCursorY);
}

float FGameplayDebugger_DisplayDebugManager::GetMaxCharHeight() const
{
	return CanvasContext.Font->GetMaxCharHeight();
}

void FGameplayDebugger_DisplayDebugManager::ShiftYDrawPosition(const float& YOffset)
{
	CanvasContext.CursorY += YOffset;
	MaxCursorY = FMath::Max(CanvasContext.CursorY, MaxCursorY);
	AddColumnIfNeeded();
}

#endif
