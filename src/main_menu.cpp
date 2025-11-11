#include "main_menu.h"
#include <godot_cpp/classes/button.hpp>

MainMenu::MainMenu() {
}

void MainMenu::_ready() {
	find_and_connect_button_down("Container/PlayVsAi", "on_play_vs_ai_button_down");
	find_and_connect_button_down("Container/Host", "on_host_button_down");
	find_and_connect_button_down("Container/Join", "on_join_button_down");
	find_and_connect_button_down("Container/Settings", "on_settings_button_down");
	find_and_connect_button_down("Container/Exit", "on_exit_button_down");
}

void MainMenu::_bind_methods() {
	ClassDB::bind_method(D_METHOD("on_play_vs_ai_button_down"), &MainMenu::on_play_vs_ai_button_down);
	ClassDB::bind_method(D_METHOD("on_host_button_down"), &MainMenu::on_host_button_down);
	ClassDB::bind_method(D_METHOD("on_join_button_down"), &MainMenu::on_join_button_down);
	ClassDB::bind_method(D_METHOD("on_settings_button_down"), &MainMenu::on_settings_button_down);
	ClassDB::bind_method(D_METHOD("on_exit_button_down"), &MainMenu::on_exit_button_down);
}

void MainMenu::find_and_connect_button_down(const NodePath &in_path, const StringName &in_method_name) {
	Button *button = get_node<Button>(in_path);
	if (button == nullptr) {
		return;
	}
	button->connect("button_down", Callable(this, in_method_name));
}

void MainMenu::on_play_vs_ai_button_down() {
	godot::print_line("PlayVsAI button has been pressed");
}

void MainMenu::on_host_button_down() {
	godot::print_line("Host button has been pressed");
}

void MainMenu::on_join_button_down() {
	godot::print_line("Join button has been pressed");
}

void MainMenu::on_settings_button_down() {
	godot::print_line("Settings button has been pressed");
}

void MainMenu::on_exit_button_down() {
	godot::print_line("Exit button has been pressed");
}
