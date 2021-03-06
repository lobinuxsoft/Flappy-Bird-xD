#include "Button.h"

namespace GameCore
{
    void Button::mouseCollision()
    {
        hover = CheckCollisionPointRec(GetMousePosition(), rect);
        press = hover && IsMouseButtonDown(0);
        click = hover && IsMouseButtonReleased(0);
    }

    Button::Button(Vector2 position, std::string text, const char clickSfxUrl[], int fontSize, float hMargin, float vMargin, float roundness, int segment, int tickness, Color textColor, Color normalColor, Color pressColor) :
        Entity{ position },
        text(text),
        clickSfx(LoadSound(clickSfxUrl)),
        fontSize(fontSize),
        hMargin(hMargin),
        vMargin(vMargin),
        roundness(roundness),
        segment(segment),
        tickness(tickness),
        textColor(textColor),
        normalColor(normalColor),
        pressColor(pressColor) { }

    Button::~Button()
    {
        UnloadSound(clickSfx);
    }

    void Button::setPivot(Vector2 pivot)
    {
        this->pivot = pivot;
    }

    void Button::setText(std::string text, Color color)
    {
        this->text = text;
        this->textColor = color;
    }

    void Button::setNormalColor(Color color)
    {
        this->normalColor = color;
    }

    void Button::setPressColor(Color color)
    {
        this->pressColor = color;
    }

    bool Button::isClick()
    {
        if (click) PlaySound(clickSfx);
        return click;
    }

    void Button::update()
    {
        mouseCollision();
    }

    void Button::draw()
    {

        float deltaX = position.x - (hMargin * 2 + MeasureText(text.c_str(), fontSize)) * pivot.x;
        float deltaY = position.y - (vMargin * 2 + fontSize) * pivot.y;

        rect = Rectangle
        {
            deltaX,
            deltaY,
            hMargin * 2 + MeasureText(text.c_str(), fontSize),
            vMargin * 2 + fontSize
        };

        DrawRectangleRoundedLines(rect, roundness, segment, tickness, press ? normalColor : pressColor);
        DrawRectangleRounded(rect, roundness, segment, press ? pressColor : normalColor);
        DrawText(text.c_str(), static_cast<int>(rect.x + hMargin), static_cast<int>(rect.y + vMargin), fontSize, textColor);

#if _DEBUG
        DrawLine(static_cast<int>(position.x), 0, static_cast<int>(position.x), GetScreenHeight(), WHITE);
        DrawLine(0, static_cast<int>(position.y), GetScreenWidth(), static_cast<int>(position.y), WHITE);
        DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), 5.0f, WHITE);
#endif
    }
}