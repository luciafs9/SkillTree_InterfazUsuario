## Descripción general

- Sistema de interfaz de usuario para un **árbol de habilidades (Skill Tree)** en **Unreal Engine 5**, implementado en **C++** y **Blueprints**.  
- El árbol está dividido en **tres bloques principales**: **Health**, **Skill** y **Strength**, cada uno con sus propias habilidades desbloqueables.  
- El jugador puede gastar puntos de mejora para activar nuevas habilidades, siempre que cumpla los requisitos necesarios.  
- El menú del árbol se abre desde el **Blueprint del personaje** al presionar la tecla **E**.

---

## Estructura de clases

### **USkillTree**
**Archivo:** `SkillTree.h / SkillTree.cpp`

Widget principal del sistema. Gestiona el estado general del árbol de habilidades y coordina todos los botones.

**Funciones clave:**
- **`NativeConstruct()`**
  - Inicializa el widget y asigna a cada `USkillButtons` una referencia al árbol.
  - Clasifica los botones según su categoría (`Health`, `Strength`, `Skills`) en distintos `TMap`.
  - Muestra inicialmente los puntos disponibles (`m_puntosmejora = 78`).

- **`CanUnlockButton()`**
  - Comprueba si una habilidad cumple los prerrequisitos para desbloquearse.

- **`ModifySkillPoints()`**
  - Resta el coste de la habilidad al desbloquearla y actualiza el texto visible.
  - Si no hay puntos suficientes, muestra una advertencia temporal.

**Atributos destacados:**
- `m_puntosmejora`: puntos disponibles para gastar.  
- `SkillButtonsHealth`, `SkillButtonsStrength`, `SkillButtonsSkills`: mapean habilidades por categoría.  
- `BP_ConfirmationWindow`: referencia al widget de confirmación.  

---

### **USkillButtons**
**Archivo:** `SkillButtons.h / SkillButtons.cpp`

Representa cada **botón individual** del árbol de habilidades.

**Estructura asociada:**
- `FSkillData`: contiene datos de la habilidad (`SkillID`, coste, prerrequisitos, categoría, estado activo).

**Funciones clave:**
- **`NativeConstruct()`**
  - Asigna el evento `OnClicked` al botón.
- **`OnButtonClicked()`**
  - Verifica si la habilidad puede desbloquearse y si hay puntos suficientes.
  - Si es posible, muestra una ventana de confirmación (`UConfirmationWindow`).
  - Si no, cambia el color del botón temporalmente a rojo como advertencia.
- **`UnlockButton()`**
  - Marca la habilidad como activa, resta puntos y cambia el color del botón a verde.
  - Desactiva el botón para evitar que se vuelva a usar.
  - Emite el evento `OnSkillUnlocked`, escuchado por `USkillTree`.

---

### **UConfirmationWindow**
**Archivo:** `ConfirmationWindow.h / ConfirmationWindow.cpp`

Ventana emergente que aparece al intentar desbloquear una habilidad.

**Funciones clave:**
- **`ConfirmAction()`**
  - Emite el evento `OnConfirm` y oculta la ventana.
- **`CancelAction()`**
  - Simplemente oculta la ventana sin realizar cambios.

**Atributos:**
- `ButtonConfirm` y `ButtonCancel`: botones que controlan la acción del usuario.  
- `OnConfirm`: delegado que se enlaza dinámicamente desde `USkillButtons` cuando se abre la ventana.

