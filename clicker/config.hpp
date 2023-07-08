#pragma once

#include <shlobj.h>
#include <fstream>
#include <filesystem>

class c_config
{
private:
	std::filesystem::path path;
	std::vector<std::string> configs;

public:
	void run( std::string name );
	void load( size_t id );
	void save( size_t id ) const;
	void add( std::string name );
	void remove( size_t id );
	void rename( size_t item, std::string new_name );
	void reset();

	constexpr auto& get_configs() { return configs; };
	constexpr auto& get_path() { return path; };

	struct
	{
		int i_clicker_key { 0 };
		int i_clicker_key_right { 0 };

		int i_key_type { 0 };
		int i_version_type { 0 };

		bool b_enable_left_clicker { false };
		bool b_enable_right_clicker { false };

		bool t_MC_found{ false };

		bool k_use_left{ false };
		bool k_use_right{ false };

		float f_left_cps { rng::random_real<float>( 9.5f, 12.5f ) };
		float f_right_cps { rng::random_real<float>( 9.5f, 12.5f ) };

		bool b_enable_blatant { false };

		int i_hide_window_key{ 0 };

		bool f_hide_window{ false };

		bool b_enable_advanced_options { false };

		bool b_enable_persistence { true };
		float f_persistence_value { rng::random_real<float>( 1.f, 5.f ) };

		float f_persistence_update_rate { 3000.f };
		float f_default_timer_randomization { 5.f };

		int i_cps_spike_chance { 5 };
		float f_cps_spike_add { 2.5f };

		int i_cps_drop_chance { 15 };
		float f_cps_drop_remove { 3.5f };

		bool b_enable_cps_spikes { false };
		bool b_enable_cps_drops { false };

		bool b_only_in_game { false };

		float f_color_accent[4]{ 0.0f, 0.24f, 0.44f, 1.0f }; // #003D71FF
		float f_color_accent_hovered[4]{ 0.12f, 0.16f, 0.32f, 1.0f }; // #1E2952FF
		float f_color_accent_active[4]{ 0.0f, 0.18f, 0.36f, 1.0f }; // #002F5DFF
		float f_color_accent_text[4]{ 1.0f, 1.0f, 1.0f, 1.0f }; // #FFFFFFFF


		std::string str_window_title;
	} clicker;
};

inline auto config = c_config();