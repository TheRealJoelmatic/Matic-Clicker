#pragma once

enum keybind_state_t : int
{
    toggle,
    hold
};

class keybind
{
public:
    bool b_state = false;
    bool keyDown = false;

    int i_mode = 0;
    int i_key = 0;

    keybind() = default;
    explicit keybind(bool state, int mode = 0, int key = 0)
    {
        b_state = state;
        i_key = key;
    }

    bool get()
    {

        switch (i_mode)
        {
        case keybind_state_t::toggle:
            if (config.clicker.i_clicker_key)
            {
                if (GetAsyncKeyState(config.clicker.i_clicker_key) & 0x8000) {
                    if (!keyDown) {
                        keyDown = true;
                        std::cout << "Key pressed!" << config.clicker.b_enable_left_clicker << std::endl;
                        return false;
                    }
                }
                else {
                    if (keyDown) {
                        keyDown = false;
                        if (config.clicker.k_use_left) {
                            config.clicker.b_enable_left_clicker = !config.clicker.b_enable_left_clicker;
                        }
                        if (config.clicker.k_use_right) {
                            config.clicker.b_enable_right_clicker = !config.clicker.b_enable_right_clicker;
                        }
                        std::cout << "Key Released!" << config.clicker.b_enable_left_clicker << std::endl;

                        return false;
                    }
                }
            }

            break;

        case keybind_state_t::hold:
            if (GetAsyncKeyState(config.clicker.i_clicker_key) & 0x8000) {
                //std::cout << "Started holding" << std::endl;
                config.clicker.b_enable_left_clicker = true;
                return false;
            }
            else {
                //std::cout << "Stopped holding" << std::endl;
                config.clicker.b_enable_left_clicker = false;
                return false;
            }
            break;
        }
        return false;
    }

    bool rightdown() {
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
            return true;
        }
        return false;
    }

    bool leftdown() {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            return true;
        }
        return false;
    }
};