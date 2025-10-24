#pragma once

#include <godot_cpp/classes/control.hpp>

using namespace godot;

class MainMenu : public Control
{
	GDCLASS(MainMenu, Control);

public:
	MainMenu();
	virtual void _ready() override;

protected:
	static void _bind_methods();

private:
	void find_and_connect_button_down(const NodePath& in_path, const StringName& in_method_name);
	void on_play_vs_ai_button_down();
	void on_host_button_down();
	void on_join_button_down();
	void on_settings_button_down();
	void on_exit_button_down();
};
