#include "player.h"

void player::update(const bool game_over, const bool countdown_active)
{
	if (!countdown_active)
	{
		if (IsKeyPressed(KEY_SPACE) && !game_over)
		{
			velocity_.y = -30.f;
		}
		else
		{
			velocity_.y += 0.5f;
		}
	}

	velocity_ = Vector2ClampValue(velocity_, -30, max_velocity_);

	position_.y += velocity_.y;
	position_.y = Clamp(position_.y, 0, 900);

	rotation_ = velocity_.y;

	rectangle_.x = position_.x;
	rectangle_.y = position_.y;
	rectangle_.width = size_.x;
	rectangle_.height = size_.y;
}

void player::draw() const
{
	DrawRectanglePro(rectangle_, origin_, rotation_, color_);
	//DrawText(TextFormat("Velocity: %f %f ", velocity_.x, velocity_.y), 1, 700, 20, BLACK);
	//DrawText(TextFormat("Position: %f %f ", position_.x, position_.y), 1, 721, 20, BLACK);
}

Vector2 player::get_position() const
{
	return position_;
}

bool player::is_off_screen() const
{
	return position_.y > 800;
}

Rectangle player::get_rect() const
{
	return Rectangle{
		rectangle_.x - origin_.x,
		rectangle_.y - origin_.y,
		rectangle_.width - origin_.x,
		rectangle_.height - origin_.y
	};
}

void player::reset()
{
	velocity_ = { 0 , 0 };
	size_ = { 64, 64 };
	position_ = { 450.f / 2.f - size_.x / 2.f, 800.f / 2.f - size_.y / 2.f };
	rotation_ = 0;
}

void player::set_velocity(const Vector2 velocity)
{
	velocity_ = velocity;
}
