#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void AddControls(HWND hWnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    const wchar_t kClassName[] = L"SimpleGUICalculator";
    
    WNDCLASSEXW wc = {0};

    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = kClassName;

    if (!RegisterClassExW(&wc))
    {
        return 1;
    }

    const DWORD kMainWindowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
        | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

    RECT window_rect = {0};

    window_rect.bottom = 280;
    window_rect.left = 0;
    window_rect.right = 370;
    window_rect.top = 0;

    AdjustWindowRect(&window_rect, kMainWindowStyle, FALSE);

    HWND main_window = CreateWindowW(kClassName, L"Calculator",
        kMainWindowStyle, CW_USEDEFAULT, CW_USEDEFAULT,
        window_rect.right - window_rect.left,
        window_rect.bottom - window_rect.top, NULL, NULL, hInstance, NULL);

    if (!main_window)
    {
        return 1;
    }

    ShowWindow(main_window, nCmdShow);

    MSG msg = {0};

    while (GetMessageW(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

void AddControls(HWND hWnd)
{
    const DWORD kTextStaticStyle = WS_VISIBLE | WS_CHILD | SS_RIGHT;
    const DWORD kEditStyle = WS_VISIBLE | WS_CHILD | ES_RIGHT;
    const DWORD kButtonStyle = WS_VISIBLE | WS_CHILD;

    CreateWindowW(L"STATIC", L"", kTextStaticStyle, 20, 40, 330, 15, hWnd,
        NULL, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"EDIT", L"", kEditStyle, 20, 65, 330, 23, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"CE", kButtonStyle, 20, 100, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"C", kButtonStyle, 105, 100, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"<--", kButtonStyle, 190, 100, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"/", kButtonStyle, 275, 100, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"7", kButtonStyle, 20, 135, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"8", kButtonStyle, 105, 135, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"9", kButtonStyle, 190, 135, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"*", kButtonStyle, 275, 135, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"4", kButtonStyle, 20, 170, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"5", kButtonStyle, 105, 170, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"6", kButtonStyle, 190, 170, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"-", kButtonStyle, 275, 170, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"1", kButtonStyle, 20, 205, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"2", kButtonStyle, 105, 205, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"3", kButtonStyle, 190, 205, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"+", kButtonStyle, 275, 205, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"+/-", kButtonStyle, 20, 240, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"0", kButtonStyle, 105, 240, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L",", kButtonStyle, 190, 240, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    CreateWindowW(L"BUTTON", L"=", kButtonStyle, 275, 240, 75, 25, hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
}