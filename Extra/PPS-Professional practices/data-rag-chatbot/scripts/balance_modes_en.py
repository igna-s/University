import matplotlib.pyplot as plt
import numpy as np

# Data in order: 
# Free Mode: [Gemini, GPT-OSS]
# Restricted Mode: [Gemini, GPT-OSS]
data_free = [[79.0, 21.0], [27.0, 73.0]]
data_restricted = [[91.0, 9.0], [94.0, 6.0]]

# Translated models and categories
models = ['Google Gemini\nFlash-2.5', 'OpenAI\nGPT-OSS-20b']
labels = ['Taxonomy', 'Internal Knowledge']
colors = ["#45CAFF", "#FF8D2F"]

# Create figure with 1 row and 2 columns
fig, (ax_free, ax_restricted) = plt.subplots(1, 2, figsize=(16, 8))

def create_pies_in_axis(ax, model_data, title):
    # Create 2 subaxes within the main axis
    left_box = ax.inset_axes([0.02, 0.1, 0.45, 0.8])
    right_box = ax.inset_axes([0.53, 0.1, 0.45, 0.8])
    
    axes_list = [left_box, right_box]
    all_wedges = []
    
    for i, (eje, data) in enumerate(zip(axes_list, model_data)):
        wedges, texts, autotexts = eje.pie(
            data,
            autopct='%1.1f%%',
            startangle=90,
            colors=colors,
            # Font weight set to normal
            textprops={'color': 'white', 'weight': 'normal', 'fontsize': 12},
            pctdistance=0.6,
            labeldistance=1.1,
            wedgeprops={
                'edgecolor': 'white', 
                'linewidth': 2, 
                'linestyle': '-',
                'alpha': 0.9
            }
        )
        
        all_wedges.extend(wedges)
        
        # Customize percentages - Normal weight
        for autotext in autotexts:
            autotext.set_fontsize(12)
            autotext.set_fontweight('normal')
            autotext.set_color('white')
            
            x, y = autotext.get_position()
            norm = np.sqrt(x**2 + y**2)
            if norm > 0:
                autotext.set_position((x * 0.85, y * 0.85))
        
        for text in texts:
            text.set_visible(False)
        
        # Model title below each pie - Normal weight
        eje.set_title(models[i], y=-0.2, fontsize=12, fontweight='normal', color='#2C3E50')
        
        for spine in eje.spines.values():
            spine.set_visible(False)
        
        eje.set_aspect('equal')
    
    # Mode title at the top - Normal weight
    ax.text(0.5, 0.95, title, transform=ax.transAxes,
            fontsize=16, fontweight='normal', ha='center', va='top',
            color='#2C3E50')
    
    ax.axis('off')
    return all_wedges

# Create pies in Free Mode
wedges_free = create_pies_in_axis(ax_free, data_free, 'Free Mode')

# Create pies in Restricted Mode
wedges_restricted = create_pies_in_axis(ax_restricted, data_restricted, 'Restricted Mode')

# Main title - Normal weight
fig.text(0.5, 0.98, 'Scenario Distribution by Response Origin',
         fontsize=18, fontweight='normal', ha='center', va='top', color='#2C3E50')

# Legend - Normal weight
fig.legend(wedges_free[:2], labels, loc='upper center', ncol=2, fontsize=13,
           bbox_to_anchor=(0.5, 0.92), frameon=True, fancybox=True,
           shadow=False, facecolor='#F8F9F9', edgecolor='#2C3E50', 
           borderpad=0.5, labelspacing=1)

plt.tight_layout()
plt.subplots_adjust(top=0.88, bottom=0.08, wspace=0.1)

plt.show()
