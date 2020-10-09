// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameJoltLogin.generated.h"

class UButton;
class UEditableTextBox;

/**
 * 
 */
UCLASS(Abstract)
class GAMEJOLTUI_API UGameJoltLogin : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* UserNameBox;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* UserTokenBox;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, OptionalWidget = true))
	UButton* LoginButton;

protected:

	UFUNCTION()
	void TextChanged(const FText& Text);

	UFUNCTION()
	void Login();

	UFUNCTION()
	void OnFailure();

	UFUNCTION()
	void OnSuccess();
};
