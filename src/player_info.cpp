#include "player_info.h"
#include <godot_cpp/core/class_db.hpp>

PlayerInfo::PlayerInfo() {
	_name = StringName();
	_ready = false;
	_loaded = false;
}

const StringName &PlayerInfo::get_name() const {
	return _name;
}

void PlayerInfo::set_name(const StringName &in_name) {
	_name = in_name;
}

bool PlayerInfo::is_ready() const {
	return _ready;
}

void PlayerInfo::set_ready(const bool in_ready) {
	_ready = in_ready;
}

bool PlayerInfo::has_loaded() const {
	return _loaded;
}

void PlayerInfo::set_loaded(const bool in_loaded) {
	_loaded = in_loaded;
}

void PlayerInfo::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("get_name"),
			&PlayerInfo::get_name);
	ClassDB::bind_method(
			D_METHOD("set_name", "name"),
			&PlayerInfo::set_name);
	ClassDB::bind_method(
			D_METHOD("is_ready"),
			&PlayerInfo::is_ready);
	ClassDB::bind_method(
			D_METHOD("set_ready", "ready"),
			&PlayerInfo::set_ready);
	ClassDB::bind_method(
			D_METHOD("is_loaded"),
			&PlayerInfo::has_loaded);
	ClassDB::bind_method(
			D_METHOD("is_loaded", "loaded"),
			&PlayerInfo::set_loaded);
}
