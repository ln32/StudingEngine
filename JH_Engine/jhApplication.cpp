#include "jhApplication.h"

namespace jh
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mX(0.0f)
		, mY(0.0f)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update(); // 입력 피드백
		LateUpdate();
		Render(); // 출력 피드백
	}
	void Application::Update()
	{
		mSpeed += 0.01f;

		// 내가 오른쪾 키를 입력받았다면
		// x 좌표가 플러스
		// 왼쪽 -> x 가 마이너스
		// 위아래는 y가 플러스 마이너스
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		HBRUSH tempBrush, rtnBrush;
		HPEN tempPen, rtnPen;
		if (true) {
			tempBrush = CreateSolidBrush(RGB(0, 0, 255));
			tempPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			rtnBrush = (HBRUSH)SelectObject(mHdc, tempBrush);
			rtnPen = (HPEN)SelectObject(mHdc, tempBrush);
		}

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		if (true)
		{
			SelectObject(mHdc, rtnPen);
			SelectObject(mHdc, rtnBrush);

			DeleteObject(tempBrush);
			DeleteObject(tempPen);
		}
	}
}