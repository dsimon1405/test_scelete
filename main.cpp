#include <ZC/Video/ZC_SWindow.h>

#include <ZC/Objects/Camera/ZC_Camera.h>
#include <ZC/GUI/ZC_GUI__Window.h>
#include <ZC/GUI/ZC_GUI__CheckBox.h>
#include <ZC/GUI/ZC_GUI__Text.h>

// struct Obj
// {
//     int oi;

//     Obj(int _oi)
//         : oi(_oi)
//     {}

//     virtual ~Obj() = default;

//     virtual bool VConfigure_O() { return false; }
// };

// struct ObjB : public Obj
// {
//     ObjB(int _oi)
//         : Obj(_oi)
//     {}
// };

// struct Win : public ObjB
// {
//     Win(int _oi)
//         : ObjB(_oi)
//     {}
// };

// struct Wins
// {
//     static inline Win* pWin;

//     static void AddWin(Win* _pWin)
//     {
//         pWin = _pWin;
//     }

//     void Configure()
//     {
//         bool con = pWin->VConfigure_O();
//     }
// };

// struct WinImm : public Win
// {
//     WinImm(int _oi)
//         : Win(_oi)
//     {
//         Wins::AddWin(this);
//     }

//     bool VConfigure_O() override
//     {
//         return true;
//     }
// };
#include <iostream>
void Ch_b(bool state)
{
    std::cout<<state<<std::endl;
}

int main(int argv, char** args)
{
    // Wins wins;
    // WinImm wi1(1);
    // WinImm wi2(2);
    // wins.Configure();


    ZC_SWindow::MakeWindow(ZC_SWF__GUI | ZC_SWF__Border, 800.f, 600.f, "name");
    // ZC_SWindow::NeedDrawFPS(true);
    // ZC_SWindow::SetFPS(0);

    ZC_Camera cam({0.f, -5.f, 0.f}, { 0.f, 0.f, 0.f }, { 0.f, 0.f, 1.f }, ZC_Perspective(45.f, 800.f/600.f, 0.1f, 100.f), ZC_Ortho(0.f, 800.f, 0.f, 600.f), true);
    
    ZC_GUI__WinImmutable win(ZC_WOIData(400.f, 300.f, 0.f, 0.f, ZC_WOIF__X_Center | ZC_WOIF__Y_Center), ZC_GUI_WF__Movable | ZC_GUI_WF__NeedDraw);
    ZC_GUI__Text text(L"text", true, 0, ZC_GUI_TextAlignment::Left);
    // ZC_GUI__CheckBox ch_b(ZC_GUI_TFB_Indent_Location::Left, L"name", true, { Ch_b }, nullptr);
    // win.AddRow(ZC_GUI_Row(ZC_GUI_RowParams(0.f, ZC_GUI_RowParams::Center, 5.f, 10.f), { text.GetObj(), ch_b.GetObj() }));
    win.AddRow(ZC_GUI_Row(ZC_GUI_RowParams(0.f, ZC_GUI_RowParams::Center, 5.f, 10.f), { text.GetObj() }));
    // win.AddRow(ZC_GUI_Row(ZC_GUI_RowParams(0.f, ZC_GUI_RowParams::Center, 5.f, 10.f), { ch_b.GetObj() }));

    ZC_SWindow::RunMainCycle();

    return 0;
}