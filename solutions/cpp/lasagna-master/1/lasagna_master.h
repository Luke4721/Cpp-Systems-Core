#pragma once

#include <vector>
#include <string>
namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

    inline int preparationTime(const std::vector<std::string>& ingredients,
                               int averageTimePerIngredient = 2)
    {
        return ingredients.size() * averageTimePerIngredient;
    }
    
    inline amount quantities(const std::vector<std::string>& ingredients)
    {
        int noodle_count = 0;
        double sauce_layers = 0;
    
        for (const auto& a : ingredients)
        {
            if (a == "noodles") ++noodle_count;
            else if(a == "sauce") ++sauce_layers;
        }
    
        return { noodle_count * 50, sauce_layers * 0.2 };
    }
    
    inline void addSecretIngredient(std::vector<std::string>& own,
                                    const std::vector<std::string>& friends)
    {
        own.back() = friends.back();
    }
    
    inline void addSecretIngredient(std::vector<std::string>& own,
                                    const std::string& secret)
    {
        own.back() = secret;
    }
    
    inline std::vector<double> scaleRecipe(const std::vector<double>& quantities,
                                           int portions)
    {
        std::vector<double> scaled;
        double factor = portions / 2.0;
    
        for (double q : quantities)
            scaled.push_back(q * factor);
    
        return scaled;
    }

} // namespace lasagna_master

