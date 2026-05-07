from setuptools import find_packages, setup

package_name = 'kml_exporter'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='laura_benitez',
    maintainer_email='laura_benitez@todo.todo',
    description='Package to export GPS data to KML format',  # Añade una descripción clara
    license='MIT',  # Asegúrate de poner tu licencia, o usa 'MIT' si no es específica
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'extract_to_kml = kml_exporter.extract_to_kml:main',  # Aquí está la entrada para tu nodo
        ],
    },
)
