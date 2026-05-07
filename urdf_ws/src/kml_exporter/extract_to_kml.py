import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from xml.dom.minidom import Document

class KMLExporter(Node):

    def __init__(self):
        super().__init__('kml_exporter')

        # Crea la suscripción al topic
        self.subscription = self.create_subscription(
            NavSatFix, 
            '/Cuadriga/fixposition/navsatfix', 
            self.listener_callback, 
            10)
        
        # Crea un archivo KML y la estructura básica
        self.doc = Document()
        kml = self.doc.createElement('kml')
        kml.setAttribute('xmlns', 'http://www.opengis.net/kml/2.2')
        self.doc.appendChild(kml)

        # Crea el contenedor de la etiqueta KML para colocar las marcas
        document = self.doc.createElement('Document')
        kml.appendChild(document)
        
        # Abre el archivo KML para escribir los datos
        self.kml_file = open('gps_data.kml', 'w')

    def listener_callback(self, msg):
        # Crea un marcador para cada punto con lat y lon
        latitude = msg.latitude
        longitude = msg.longitude
        timestamp = self.get_clock().now().nanoseconds

        # Crea un nuevo placemark para cada mensaje
        placemark = self.doc.createElement('Placemark')

        # Crea el nombre del placemark (puedes usar el timestamp o cualquier otro identificador)
        name = self.doc.createElement('name')
        name.appendChild(self.doc.createTextNode(str(timestamp)))
        placemark.appendChild(name)

        # Crea las coordenadas
        coordinates = self.doc.createElement('coordinates')
        coordinates.appendChild(self.doc.createTextNode(f'{longitude},{latitude},0'))
        placemark.appendChild(coordinates)

        # Añade el placemark al documento KML
        self.doc.documentElement.getElementsByTagName('Document')[0].appendChild(placemark)

    def __del__(self):
        # Escribe y cierra el archivo KML
        self.kml_file.write(self.doc.toprettyxml())
        self.kml_file.close()

def main(args=None):
    rclpy.init(args=args)
    kml_exporter = KMLExporter()
    rclpy.spin(kml_exporter)
    kml_exporter.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()