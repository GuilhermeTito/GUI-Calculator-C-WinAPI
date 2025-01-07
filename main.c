#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

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

    HWND main_window = CreateWindowW(
        kClassName,
        L"Calculator",
        kMainWindowStyle,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        window_rect.right - window_rect.left,
        window_rect.bottom - window_rect.top,
        NULL,
        NULL,
        hInstance,
        NULL
    );

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
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}