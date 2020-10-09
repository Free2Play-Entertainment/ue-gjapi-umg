// Copyright by Free2Play-Entertainment (2020)


#include "GameJoltLogin.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "AsyncActions/Users/Login.h"

void UGameJoltLogin::NativeConstruct()
{
    if(UserNameBox)
        UserNameBox->OnTextChanged.AddDynamic(this, &UGameJoltLogin::TextChanged);
    if(UserTokenBox)
        UserTokenBox->OnTextChanged.AddDynamic(this, &UGameJoltLogin::TextChanged);

    if(LoginButton)
        LoginButton->OnClicked.AddDynamic(this, &UGameJoltLogin::Login);
}

void UGameJoltLogin::TextChanged(const FText& Text)
{
    if(UserNameBox->Text.ToString().Len() == 0 || UserTokenBox->GetText().ToString().Len() == 0)
        LoginButton->SetIsEnabled(false);
    else
        LoginButton->SetIsEnabled(true);
}

void UGameJoltLogin::Login()
{
    ULogin* LoginNode = ULogin::Login(UserNameBox->Text.ToString(), UserTokenBox->Text.ToString());
    LoginNode->Failure.AddDynamic(this, &UGameJoltLogin::OnFailure);
    LoginNode->Success.AddDynamic(this, &UGameJoltLogin::OnSuccess);
    LoginNode->Activate();
}

void UGameJoltLogin::OnFailure()
{

}

void UGameJoltLogin::OnSuccess()
{

}