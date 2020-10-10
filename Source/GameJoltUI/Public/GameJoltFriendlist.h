// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameJoltFriendlist.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GAMEJOLTUI_API UGameJoltFriendlist : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct();

public:

	
};
