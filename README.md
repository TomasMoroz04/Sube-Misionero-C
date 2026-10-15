# 🚌 SUBEMISIONERO - Sistema de Gestión de Transporte Urbano

Trabajo Práctico Integrador desarrollado en **lenguaje C** para la cátedra de **Programación Estructurada** (1.° año de Ingeniería en Informática, UGD). 

El sistema simula la operatoria de la tarjeta SUBE y Billetera Electrónica en el área metropolitana de **Posadas, Garupá y Candelaria (Misiones)**, incluyendo validación de beneficios sociales, recarga de saldo con emisión de comprobantes y un panel administrativo de estadísticas y auditoría.

---

## 👥 Contexto del Proyecto y Créditos

Este trabajo refleja el **esfuerzo colaborativo de 3 estudiantes** desarrollado durante nuestro primer año en la carrera. La versión aquí publicada captura el código fuente del proyecto final entregado y defendido para la aprobación de la materia, demostrando las bases lógicas y algorítmicas adquiridas en programación estructurada.

**Equipo de Desarrolladores:**
* F. Fernandez
* M. Landro
* **Tomás Moroz** *(Curador de este repositorio)*

---

## 🛠️ Aspectos Técnicos Implementados

- **Lenguaje:** C estándar (`stdio.h`, `stdlib.h`, `string.h`, `time.h`).
- **Persistencia de datos:** Manejo de archivos binarios (`.dat`) con lectura/escritura directa (`rb`, `ab`, `r+b`) y posicionamiento de punteros (`fseek`) para actualización de saldos y perfiles *in-place*.
- **Generación de tickets:** Exportación de comprobantes de recarga en texto plano (`comprobante.txt`) con marca de tiempo real del sistema (`localtime` / `strftime`).
- **Modelado de entidades:** Estructuras (`struct`) relacionadas mediante DNI y número de unidad para `Usuario`, `Cuenta`, `Boleto`, `Recarga`, `Chofer` y `Colectivo`.

---

## ⚙️ Funcionalidades Principales

### 👤 Módulo de Usuarios
- **Registro e Inicio de Sesión:** Validación de unicidad de DNI y número de teléfono contra los archivos binarios.
- **Categorías y Beneficios Tarifarios:** Soporte para tarifa Normal, Boleto Estudiantil Gratuito (BEEG), Certificado Único de Discapacidad (CUD), Adultos Mayores (validación automática por fecha de nacimiento) y Ex-Combatientes de Malvinas.
- **Gestión de Saldo:** Consulta en tiempo real y recarga por distintas bocas de pago con emisión de comprobante.
- **Pago de Boletos:** Cobro mediante tarjeta SUBE o Billetera Electrónica (validando teléfono) a través de 9 tramos urbanos e interurbanos con cuadro tarifario diferenciado.

### 📊 Módulo de Administración y Consultas
- Alta y registro de unidades de colectivo y plantel de choferes.
- Padrón general de usuarios registrados y conteo de beneficiarios sociales.
- Auditoría de viajes realizados filtrando por rango de fechas (`DD/MM/AAAA`) o por nombre de pasajero.
- Historial detallado de recargas por DNI.
- **Métricas operativas:** Cálculo del chofer con mayor cantidad de pasajeros transportados por mes (cruzando horarios de viaje con turnos asignados) y porcentaje de viajes realizados en el turno mañana.

---

## 🗺️ Diagrama de Flujo del Sistema

![Diagrama de Flujo SUBEMISIONERO](DIAGRAMA_DE_FLUJO_tpi.png)

---

## 🚀 Cómo compilar y ejecutar

```bash
gcc TPI_ENTREGA.c -o subemisionero
./subemisionero
