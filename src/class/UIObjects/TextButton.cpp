#include "TextButton.h"

void TextButton::mouseCollision()
{
    hover = CheckCollisionPointRec(GetMousePosition(), rect);
    press = hover && IsMouseButtonDown(0);
    click = hover && IsMouseButtonReleased(0);
}

TextButton::TextButton(Vector2 position, string text, int fontSize, string linkUrl, Color normalColor, Color hoverColor, Color pressColor)
    : Entity{ position }, text(text), fontSize(fontSize), linkUrl(linkUrl), normalColor(normalColor), hoverColor(hoverColor), pressColor(pressColor) { }

TextButton::~TextButton() { }

void TextButton::setPivot(Vector2 pivot)
{
    this->pivot = pivot;
}

void TextButton::setText(string text)
{
    this->text = text;
}

bool TextButton::isClick()
{
    if(click && linkUrl != "") OpenURL(linkUrl.c_str());
    return click;
}

void TextButton::update()
{
    mouseCollision();
}

void TextButton::draw()
{
    float deltaX = position.x - MeasureText(text.c_str(), fontSize) * pivot.x;
    float deltaY = position.y - fontSize * pivot.y;

    rect = Rectangle
    {
        deltaX,
        deltaY,
        (float)MeasureText(text.c_str(), fontSize),
        (float)fontSize
    };

    if (press)
    {
        DrawText(text.c_str(), rect.x, rect.y, fontSize, pressColor);
    }
    else if (hover)
    {
        DrawText(text.c_str(), rect.x, rect.y, fontSize, hoverColor);
    }
    else
    {
        DrawText(text.c_str(), rect.x, rect.y, fontSize, normalColor);
    }
    

#if _DEBUG
    DrawLine(position.x, 0, position.x, GetScreenHeight(), WHITE);
    DrawLine(0, position.y, GetScreenWidth(), position.y, WHITE);
    DrawCircle(position.x, position.y, 5.0f, WHITE);
#endif
}

