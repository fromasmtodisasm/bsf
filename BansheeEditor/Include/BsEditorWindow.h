#pragma once

#include "BsEditorPrerequisites.h"
#include "BsEditorWindowBase.h"

namespace BansheeEngine
{
	/**
	 * @brief	A draggable and resizeable window that has a single widget container
	 *			you may use for docking editor widgets in.
	 */
	class BS_ED_EXPORT EditorWindow : public EditorWindowBase
	{
	public:
		virtual ~EditorWindow();

		/**
		 * @brief	Returns the widget container for this window.
		 */
		EditorWidgetContainer& widgets() const { return *mWidgets; }

		/**
		 * @copydoc	EditorWindowBase::update 
		 */
		virtual void update() override;

		/**
		 * @brief	Creates a new empty editor window.
		 */
		static EditorWindow* create();

	protected:
		friend class EditorWindowManager;
		EditorWindow();

		/**
		 * @copydoc	EditorWindowBase::resized 
		 */
		virtual void resized() override;
	private:
		EditorWidgetContainer* mWidgets;

		/**
		 * @brief	Updates the sizes of the child widget container and
		 *			OS non-client areas (like drag and resize). Call when window
		 *			size changes.
		 */
		void updateSize();

		/**
		 * @brief	Called when a widget is added to the widget container.
		 */
		void widgetAdded();

		/**
		 * @brief	Called when a widget is removed from the widget container.
		 */
		void widgetRemoved();

		/**
		 * @brief	A callback that triggers when a drag and drop operation originated from
		 *			this window ends. 
		 *
		 * @note	This is a workaround to get around the problem that closing the window
		 *			when the drag operation starts (e.g. if the last widget is dragged from the window)
		 *			will cause the application to lose mouse capture and will not receive mouse events.
		 *			Therefore we delay the window closing until the drag ends.
		 */
		void closeWindowDelayed();
	};
}