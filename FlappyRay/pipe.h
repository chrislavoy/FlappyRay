#pragma once
#include <raylib.h>

class pipe
{
	// Constants
	const float pipe_gap_{ 125.f };

	// Properties
	Vector2 position_{ 500, 400 };
	float thickness_{ 75.f };
	bool is_past_player_{ false };
	Rectangle upper_rect_{};
	Rectangle lower_rect_{};

public:
	// Functions
	pipe() = default;
	~pipe() = default;
	void update();
	void draw() const;
	void reset_pipe(float new_x, float new_y);
	bool is_off_screen() const;
	Vector2 get_position() const;
	void set_is_past_player(bool value);
	bool get_is_past_player() const;
	bool is_player_colliding(Vector2 player_pos) const;
};

