import matplotlib.pyplot as plt
import numpy as np
import matplotlib.patches as mpatches
from matplotlib.offsetbox import OffsetImage, AnnotationBbox

# Function to load icons
def get_icon(path, zoom=0.025):
    try:
        return OffsetImage(plt.imread(path), zoom=zoom)
    except:
        return None

# Load icons (Asegúrate de tener estos archivos en tu directorio)
icon_gpt = get_icon("logo_gpt.png")
icon_gemini = get_icon("logo_gemini.png")

# DATA
categorias = ['X', 'X+', 'OK-', 'OK', 'Perfect P', 'Global P']
pruebas = ['No Tax', 'With Tax', 'Free', 'Restricted']

gpt_data = np.array([
    [47, 27, 13, 13], [14, 13, 4, 3], [10, 17, 11, 14], [13, 40, 31, 37], [10, 12, 9, 10], [29, 50, 42, 57]
])

gemini_data = np.array([
    [47, 27, 16, 15], [13, 14, 4, 5], [10, 17, 5, 9], [13, 40, 80, 81], [10, 12, 16, 16], [29, 50, 85, 90]
])

colores_cat = {
    'X': ("#ffcfcf", "#871A1A"), 'X+': ("#ffd8b0", "#a5601b"),
    'OK-': ("#ffffb5", "#7F7F10"), 'OK': ("#c0ffc0", "#1E791E"),
    'Perfect P': ("#bbdcff", "#125da8"), 'Global P': ("#b692d8", "#671e9b")
}

color_gpt, color_gemini = "#4A4A4A", "#E5E5E5"

fig, axes = plt.subplots(1, 6, figsize=(25, 8), sharey=False)

handles = []
labels = []

for i, (categoria, ax) in enumerate(zip(categorias, axes)):
    x = np.arange(len(pruebas))
    w_previa, w_comp = 0.35, 0.25
    
    ax.set_title(categoria, fontsize=14, fontweight='bold', color=colores_cat[categoria][1])
    
    # --- CÁLCULO DE PROMEDIOS ---
    avg_prev = (gpt_data[i][0] + gpt_data[i][1]) / 2
    avg_gpt = (gpt_data[i][2] + gpt_data[i][3]) / 2
    avg_gem = (gemini_data[i][2] + gemini_data[i][3]) / 2

    # 1. Línea promedio barras izquierda (Color idéntico a las barras)
    ax.axhline(y=avg_prev, color=colores_cat[categoria][1], linestyle='--', linewidth=1.5, alpha=0.7)
    
    # 2. Línea promedio GPT (Gris oscuro)
    ax.axhline(y=avg_gpt, color=color_gpt, linestyle='--', linewidth=1.5, alpha=0.8)
    
    # 3. Línea promedio Gemini (Gris claro/medio para visibilidad)
    ax.axhline(y=avg_gem, color="#A0A0A0", linestyle='--', linewidth=1.5, alpha=0.8)

    # Configuración de leyenda (solo en el primer subplot para evitar duplicados)
    if i == 0:
        handles.append(plt.Line2D([0], [0], color='#666666', linestyle='--', label='Prev. Average'))
        handles.append(plt.Line2D([0], [0], color=color_gpt, linestyle='--', label='GPT Average'))
        handles.append(plt.Line2D([0], [0], color="#A0A0A0", linestyle='--', label='Gemini Average'))
        labels.extend(['Prev. Average', 'GPT Average', 'Gemini Average'])

    # --- DIBUJO DE BARRAS ---
    # Barras rayadas (Etapa previa)
    for j in [0, 1]:
        val = gpt_data[i][j] 
        ax.bar(x[j], val, w_previa, facecolor=colores_cat[categoria][0], 
               hatch='///', edgecolor=colores_cat[categoria][1])
        ax.text(x[j], val + 1, f'{val}', ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    if i == 0:
        patch_prev = mpatches.Patch(facecolor='#f0f0f0', hatch='///', edgecolor='#666666')
        handles.append(patch_prev)
        labels.append('Previous stage')

    # Barras comparativas con Iconos
    for j in [2, 3]:
        p_gpt, p_gem = x[j] - w_comp/2, x[j] + w_comp/2
        
        bar_gpt = ax.bar(p_gpt, gpt_data[i][j], w_comp, color=color_gpt, edgecolor='black')
        bar_gem = ax.bar(p_gem, gemini_data[i][j], w_comp, color=color_gemini, edgecolor='black')
        
        if i == 0 and j == 2:
            handles.append(bar_gpt)
            labels.append('OpenAI-GPT')
            handles.append(bar_gem)
            labels.append('Google-Gemini')
        
        y_off = 8
        if icon_gpt: ax.add_artist(AnnotationBbox(icon_gpt, (p_gpt, gpt_data[i][j] + y_off), frameon=False))
        if icon_gemini: ax.add_artist(AnnotationBbox(icon_gemini, (p_gem, gemini_data[i][j] + y_off), frameon=False))
        
        ax.text(p_gpt, gpt_data[i][j] + 1, f'{gpt_data[i][j]}', ha='center', va='bottom', fontsize=8)
        ax.text(p_gem, gemini_data[i][j] + 1, f'{gemini_data[i][j]}', ha='center', va='bottom', fontsize=8)

    ax.set_xticks(x)
    ax.set_xticklabels(pruebas, fontsize=9, rotation=45)
    ax.set_ylim(0, max(gpt_data[i].max(), gemini_data[i].max()) + 25)
    ax.grid(True, alpha=0.15, axis='y')

# LEYENDA SUPERIOR
fig.legend(handles, labels, 
           loc='upper center', 
           bbox_to_anchor=(0.5, 0.94), 
           ncol=len(handles), 
           fontsize=10, 
           frameon=True, 
           handlelength=2.5, 
           handleheight=1.2, 
           columnspacing=1.2, # Controla el espacio entre cada etiqueta
           borderaxespad=0.)

plt.suptitle('Metrics Comparison by Category', fontsize=20, fontweight='bold', y=0.98)
plt.subplots_adjust(top=0.75, bottom=0.15, wspace=0.3, left=0.05, right=0.95)

plt.show()