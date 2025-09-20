
#ifndef INCLUDE_PISTON_H
#define INCLUDE_PISTON_H
class Piston {
private:
    int diameter{0};
    int height{0};
    int compression_height{0};
    int count_of_cycles{0};
    int weight{0};
public:
    Piston();
    Piston(int diameter, int height, int compression_height, int count_of_cycles, int weight);
    bool set_all_parameters(int diameter, int height, int compression_height, int count_of_cycles, int weight);
    int get_diameter() const;
    int get_count_of_cycles() const;
    int get_height() const;
    int get_weight() const;
    bool check_is_piston_in_working_condition() const;
};
#endif //INCLUDE_PISTON_H
