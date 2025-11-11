#pragma once

#include <godot_cpp/classes/object.hpp>

using namespace godot;

class PlayerInfo : public Object {
	GDCLASS(PlayerInfo, Object);

public:
	PlayerInfo();
	const StringName &get_name() const;
	void set_name(const StringName &in_name);
	bool is_ready() const;
	void set_ready(const bool in_ready);
	bool has_loaded() const;
	void set_loaded(const bool in_loaded);

protected:
	static void _bind_methods();

private:
	StringName _name;
	bool _ready;
	bool _loaded;
};
