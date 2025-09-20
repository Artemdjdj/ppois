
#ifndef INCLUDE_FEELER_H
#define INCLUDE_FEELER_H
class Feeler {
private:
    int length{0};
    int level{0};
    void check_is_the_level_in_norm_state_private() const;
public:
    Feeler();
    Feeler(int length, int level);
    bool set_length(int length);
    bool set_level(int level);
    int get_length() const;
    int get_level() const;
    bool check_is_the_level_in_norm_state() const;
};
#endif //INCLUDE_FEELER_H
