import numpy as np
from collections import namedtuple

def export(raw_data: np.ndarray, output_file: str):
    variable_template = 'float CALIBRATION[' + str(len(raw_data)) + '][2] = {'
    for row in raw_data:
        variable_template += '{' + str(row[0]) + ',' + str(row[1]) + '},'
    variable_template += '};'
    
    file = f'#ifndef __CALIBRATE_H_\n#define __CALIBRATE_H_\n{variable_template}\n#endif'
    with open(output_file, "w") as f:
        f.write(file)