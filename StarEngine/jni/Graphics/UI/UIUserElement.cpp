#include "UIUserElement.h"

namespace star
{
	UIUserElement::UIUserElement(void)
		: Object()
		, m_SelectCallback(nullptr)
#ifdef _WIN32
		, m_HoverCallback(nullptr)
		, m_UnhoverCallback(nullptr)
#endif
		, m_ElementState(ElementStates::IDLE)
	{

	}

	UIUserElement::~UIUserElement(void)
	{

	}

	void UIUserElement::Initialize()
	{
		Object::Initialize();
	}

	void UIUserElement::Update(const Context& context)
	{
		Object::Update(context);
	}

	void UIUserElement::Draw()
	{
		Object::Draw();
	}

	bool UIUserElement::IsToggled() const
	{
		return m_ElementState == ElementStates::TOGGLE;
	}

	bool UIUserElement::IsDisabled() const
	{
		return m_ElementState == ElementStates::DISABLED;
	}

	void UIUserElement::SetSelectCallback(std::function<void()> callback)
	{
		m_SelectCallback = callback;
	}

#ifdef _WIN32
	void UIUserElement::SetHoverCallback(std::function<void()> callback)
	{
		m_HoverCallback = callback;
	}

	void UIUserElement::SetUnhoverCallback(std::function<void()> callback)
	{
		m_UnhoverCallback = callback;
	}
#endif
}