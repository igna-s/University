import matplotlib.pyplot as plt
import numpy as np

# Datos en el orden: 
# Modo Libre: [Gemini, GPT-OSS]
# Modo Restrictivo: [Gemini, GPT-OSS]
datos_libre = [[79, 21], [27, 73]]
datos_restrictivo = [[91, 9], [94, 6]]

modelos = ['Google Gemini\nFlash-2.5', 'OpenAI\nGPT-OSS-20b']
etiquetas = ['Taxonomía', 'Conocimiento Interno']
colores = ["#45CAFF", "#FF8D2F"]

# Crear figura con 1 fila y 2 columnas (dos grupos principales)
fig, (ax_libre, ax_restrictivo) = plt.subplots(1, 2, figsize=(16, 8))

# Función para crear dos tortas dentro de un eje
def crear_tortas_en_eje(ax, datos_modelos, titulo):
    # Crear 2 subaxes dentro del eje principal (left y right)
    left_box = ax.inset_axes([0.02, 0.1, 0.45, 0.8])
    right_box = ax.inset_axes([0.53, 0.1, 0.45, 0.8])
    
    # Lista de ejes y sus datos
    ejes = [left_box, right_box]
    todas_wedges = []
    
    for i, (eje, datos) in enumerate(zip(ejes, datos_modelos)):
        # Crear gráfico de torta - startangle=90 para que empiece a las 12 en punto
        wedges, texts, autotexts = eje.pie(
            datos,
            autopct='%1.1f%%',
            startangle=90,  # Fijo a 90 para que empiece a las 12 en punto
            colors=colores,
            textprops={'color': 'white', 'fontsize': 12},
            pctdistance=0.6,  # Ajustado para que quede fuera de la circunferencia
            labeldistance=1.1,
            wedgeprops={
                'edgecolor': 'white', 
                'linewidth': 2, 
                'linestyle': '-',
                'alpha': 0.9
            }
        )
        
        todas_wedges.extend(wedges)
        
        # Personalizar porcentajes - centrados y en blanco
        for autotext in autotexts:
            autotext.set_fontsize(12)
            autotext.set_color('white')
            autotext.set_bbox(None)  # Sin fondo
            
            # Mover ligeramente hacia afuera para evitar que quede oculto por la circunferencia
            x, y = autotext.get_position()
            # Normalizar el vector y moverlo radialmente hacia afuera
            norm = np.sqrt(x**2 + y**2)
            if norm > 0:
                # Mover en dirección radial pero manteniendo fuera del borde
                autotext.set_position((x * 0.85, y * 0.85))
        
        # Ocultar las etiquetas de las secciones
        for text in texts:
            text.set_visible(False)
        
        # Título del modelo debajo de cada torta
        eje.set_title(modelos[i], y=-0.2, fontsize=12, color='#2C3E50')
        
        # Ocultar bordes
        for spine in eje.spines.values():
            spine.set_visible(False)
        
        # Asegurar aspecto circular
        eje.set_aspect('equal')
    
    # Título del modo en la parte superior
    ax.text(0.5, 0.95, titulo, transform=ax.transAxes, fontsize=16, ha='center', va='top',color='#2C3E50')
    
    # Ocultar los ejes principales
    ax.axis('off')
    
    return todas_wedges

# Crear tortas en modo libre
wedges_libre = crear_tortas_en_eje(ax_libre, datos_libre, 'Modo Libre')

# Crear tortas en modo restrictivo
wedges_restrictivo = crear_tortas_en_eje(ax_restrictivo, datos_restrictivo, 'Modo Restrictivo')

# Referencias en la parte superior centrada
fig.text(0.5, 0.98, 'Distribución de Escenarios según Origen de la Respuesta',
         fontsize=18, ha='center', va='top', color='#2C3E50')

# Leyenda en la parte superior con estilo profesional
fig.legend(wedges_libre, etiquetas, loc='upper center', ncol=2, fontsize=13,
           bbox_to_anchor=(0.5, 0.92), frameon=True, fancybox=True,
           shadow=False, facecolor='#F8F9F9', edgecolor='#2C3E50', 
           borderpad=0.5, labelspacing=1)

# Ajustar layout
plt.tight_layout()
plt.subplots_adjust(top=0.88, bottom=0.08, wspace=0.1)

plt.show()