#pragma once
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "Particles.hpp"
#include <openPMD/openPMD.hpp>
#include <openPMD/Datatype.hpp>

namespace reduction_library{

    class Particle_reader{
        std::string file_name;
        openPMD::Series& series;

    public:
        Particle_reader(std::string file_name, openPMD::Series& series):
            file_name(file_name), series(series){}

        template<Attribute T_attribute, class T_Value>
        std::vector<double> Read_attribute(Attribute attribute, openPMD::ParticleSpecies particle_species){

            std::pair<std::string, std::string> attribute_name = state.at(attribute);
            openPMD::RecordComponent current_record = particle_species[attribute_name.first][attribute_name.second];

            std::shared_ptr<double> values_ptr = current_record.loadChunk<double>();
            series.flush();

            std::vector<std::uint64_t> values_extent = current_record.getExtent();
            int size_of_series = values_extent[0];
            series.flush();

            std::vector<T_Value> record_component_values;
            record_component_values.assign(values_ptr.get(), values_ptr.get() + size_of_series);

            return record_component_values;
        }


        Particles Read()
        {


        }



    };

}
