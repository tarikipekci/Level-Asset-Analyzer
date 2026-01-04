# Level Asset Analyzer – Unreal Engine Editor Tool

An Unreal Engine **Editor Utility Widget** developed to analyze Static Mesh Actors in large levels, organize them based on geometry complexity, and detect potential performance issues.

The tool focuses on practical level optimization workflows and editor-side analysis.

---

## Features

### Level Asset Analyzer

For each Static Mesh Actor in the level, the tool analyzes:

- **Geometry Metrics**
  - Triangle count
  - Vertex count
- **Material Metrics**
  - Number of materials used
- **Collision Metrics**
  - Collision complexity (Simple vs Complex)

Actors are categorized by triangle count:
- **Low Poly**: < 10K triangles  
- **Mid Poly**: 10K – 50K triangles  
- **High Poly**: 50K+ triangles  

---

### Automatic Organization System

- Automatically groups actors into World Outliner folders:
  - `LowPoly`
  - `MidPoly`
  - `HighPoly`
- Detects **duplicate Static Mesh usage**
- Lists meshes used by more than one actor

---

### Performance Warning System

The tool automatically generates warnings based on defined thresholds:

- **Critical**
  - Triangle count higher than 100K
- **Warning**
  - Material count greater than or equal to 5
- **Info**
  - Complex collision usage on low poly meshes

Each warning is associated with its corresponding actor and displayed in the editor UI.

---

### Editor Utility Widget UI

- Analysis results are displayed in a custom **Editor Utility Widget**
- Actors can be filtered and reviewed based on analysis results
- Clicking on an entry allows quick selection and focus in the World Outliner

---

## How to Use

1. Open the project in Unreal Engine
2. Navigate to: Content/UI
3. Run the analysis
4. Review categorized actors, warnings, and duplicate mesh usage
5. Apply automatic folder organization if needed

---

## Test Scenario

For testing purposes:

- Place 50–100 Static Mesh Actors in a level
- Use duplicate meshes (same Static Mesh asset used multiple times)
- Mix low, mid, and high poly meshes

Default Unreal meshes or free environment assets can be used.

---

## Technical Notes

- Implemented using **Blueprint-based Editor Utility Widgets**
- Designed to work efficiently on large levels
- Clear separation between analysis logic and UI representation
- Focused on pragmatic and maintainable solutions

---

## Deliverables

- Working Editor Utility Widget
- Actor analysis and categorization logic
- Automatic folder organization
- Performance warning system


