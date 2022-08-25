#include "pipe.h"

void pipe::update()
{
	position_.x -= 5.f;
	lower_rect_ = { position_.x, 0, thickness_, position_.y - pipe_gap_ };
	upper_rect_ = { position_.x, position_.y + pipe_gap_, thickness_, 800 - position_.y - pipe_gap_ };
}

void pipe::draw() const
{
	DrawRectangleRec(lower_rect_, RED);
	DrawRectangleRec(upper_rect_, RED);
}

void pipe::reset_pipe(const float new_x, const float new_y)
{
	position_ = { new_x, new_y };
	is_past_player_ = false;
}

bool pipe::is_off_screen() const
{
	return position_.x < -thickness_;
}

Vector2 pipe::get_position() const
{
	return position_;
}

void pipe::set_is_past_player(const bool value)
{
	is_past_player_ = value;
}

bool pipe::get_is_past_player() const
{
	return is_past_player_;
}

bool pipe::is_player_colliding(const Vector2 player_pos) const
{
	return CheckCollisionCircleRec(player_pos, 32, upper_rect_) || CheckCollisionCircleRec(player_pos, 32, lower_rect_);
}
