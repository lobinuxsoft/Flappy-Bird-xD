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
        DrawText(text.c_str(), static_cast<int>(rect.x), static_cast<int>(rect.y), fontSize, pressColor);
    }
    else if (hover)
    {
        DrawText(text.c_str(), static_cast<int>(rect.x), static_cast<int>(rect.y), fontSize, hoverColor);
    }
    else
    {
        DrawText(text.c_str(), static_cast<int>(rect.x), static_cast<int>(rect.y), fontSize, normalColor);
    }
    

#if _DEBUG
    DrawLine(static_cast<int>(position.x), 0, static_cast<int>(position.x), GetScreenHeight(), WHITE);
    DrawLine(0, static_cast<int>(position.y), GetScreenWidth(), static_cast<int>(position.y), WHITE);
    DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), 5.0f, WHITE);
#endif
}

